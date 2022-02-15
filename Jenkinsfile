pipeline {
  agent any
  options {
    skipDefaultCheckout true
  }
  parameters {
    booleanParam defaultValue: false, name: 'buildOnlyWiki', description: 'Only wiki updated so just copy HTML file.'
  }
  stages {
    stage('Checkout') {
      steps {
        cleanWs()
        checkout scm
      }
    }
    stage('Build') {
      when { not { expression { params.buildOnlyWiki } } }
      steps {
        sh "sed -i \"\" 's/BUILD_CI = FALSE/BUILD_CI = TRUE/' Tupfile"
	sh "chmod +x ${env.WORKSPACE}/crow/amalgamate/merge_all.py"
        sh "tup init"
        sh "tup generate ${env.WORKSPACE}/build.sh"
        sh "${env.WORKSPACE}/build.sh"
      }
    }
    stage('Checks') {
      when { not { expression { params.buildOnlyWiki } } }
      steps {
        //sh "cppcheck --library=${env.WORKSPACE}/std.cfg --suppress=missingInclude --suppress=*:${env.WORKSPACE}/src/crow.hpp --enable=all --inconclusive --template=\"{file},{line},{severity},{id},{message}\" ${env.WORKSPACE}/src 2> ${env.WORKSPACE}/cppcheck.txt"
	//recordIssues(
	//	enabledForFailure: true,
	//	aggregatingResults: true,
	//	tool: cppCheck(pattern: 'cppcheck.txt', reportEncoding: 'UTF-8')
	//)
        //step([$class: 'WarningsPublisher', parserConfigurations: [[parserName: 'cpp', pattern: "cppcheck.txt"]], usePreviousBuildAsReference: true])
	sh "cppcheck --library=${env.WORKSPACE}/std.cfg --suppress=missingInclude --suppress=*:${env.WORKSPACE}/src/crow.hpp --enable=all --inconclusive --xml --language=c++ ${env.WORKSPACE}/src 2> ${env.WORKSPACE}/cppcheck.xml"
	publishCppcheck allowNoReport: true, ignoreBlankFiles: true, pattern: '**/cppcheck.xml'
        echo "TODO Add Valgrind plugin assoon as it will be available in pipeline"
      }
    }
    stage('Test') {
      when { not { expression { params.buildOnlyWiki } } }
      steps {
        sh "mkdir ${env.WORKSPACE}/reports"
        sh "LD_LIBRARY_PATH=/home/mrozigor/libs/lib ${env.WORKSPACE}/build/tests --use-colour yes > ${env.WORKSPACE}/test_results"
        sh "cat ${env.WORKSPACE}/test_results | ansi2html > ${env.WORKSPACE}/reports/test_results.html"
        publishHTML (target: [
          allowMissing: false,
          alwaysLinkToLastBuild: false,
          keepAll: true,
          reportDir: 'reports',
          reportFiles: 'test_results.html',
          reportName: "Catch2 Report"
        ])
      }
    }
    stage('Archive') {
      when { not { expression { params.buildOnlyWiki } } }
      steps {
        sh "tar --xz -cvf server_${env.BUILD_NUMBER}.tar.xz -C ${env.WORKSPACE}/build server views assets"
        sh "cp ${env.WORKSPACE}/server_${env.BUILD_NUMBER}.tar.xz ${env.ARCHIVE_DIRECTORY}"
      }
    }
    stage('Deploy') {
      when { not { expression { params.buildOnlyWiki } } }
      steps {
        sh "kill `pgrep server` || true"
        sh "cp ${env.WORKSPACE}/build/server ${env.WEBPAGE_DIRECTORY}"
        sh "cp -r ${env.WORKSPACE}/build/views ${env.WEBPAGE_DIRECTORY}"
        sh "cp -r ${env.WORKSPACE}/build/assets ${env.WEBPAGE_DIRECTORY}"
        sh "${env.WEBPAGE_START_SCRIPT}"
      }
    }
    stage('Deploy wiki') {
       steps {
        sh "cp ${env.WORKSPACE}/wiki.html ${env.WEBPAGE_DIRECTORY}"
      }
    }
  }
}
