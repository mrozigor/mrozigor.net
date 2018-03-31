pipeline {
  agent any
  options {
    skipDefaultCheckout true
  }
  stages {
    stage('Checkout') {
      steps {
        cleanWs()
        checkout scm
      }
    }
    stage('Build') {
      steps {
        sh "sed -i \"\" 's/BUILD_CI = FALSE/BUILD_CI = TRUE/' Tupfile"
        sh "tup init"
        sh "tup generate ${env.WORKSPACE}/build.sh"
        sh "${env.WORKSPACE}/build.sh"
      }
    }
    stage('Checks') {
      steps {
        sh "cppcheck --library=${env.WORKSPACE}/std.cfg --suppress=missingInclude --suppress=*:${env.WORKSPACE}/src/crow.hpp --enable=all --inconclusive --template=\"{file},{line},{severity},{id},{message}\" ${env.WORKSPACE}/src 2> ${env.WORKSPACE}/cppcheck.txt"
        step([$class: 'WarningsPublisher', parserConfigurations: [[parserName: 'cpp', pattern: "cppcheck.txt"]], usePreviousBuildAsReference: true])
        echo "TODO Add Valgrind plugin assoon as it will be available in pipeline"
      }
    }
    stage('Test') {
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
      steps {
        sh "tar --xz -cvf server_${env.BUILD_NUMBER}.tar.xz -C ${env.WORKSPACE}/build server views ../assets"
        sh "cp ${env.WORKSPACE}/server_${env.BUILD_NUMBER}.tar.xz ${env.ARCHIVE_DIRECTORY}"
      }
    }
    stage('Deploy') {
      steps {
        sh "kill `cat /home/mrozigor/.mrozigor_net.pid` || true"
        sh "cp ${env.WORKSPACE}/build/server ${env.WEBPAGE_DIRECTORY}"
        sh "cp -r ${env.WORKSPACE}/build/views ${env.WEBPAGE_DIRECTORY}"
        sh "cp -r ${env.WORKSPACE}/assets ${env.WEBPAGE_DIRECTORY}"
        sh "${env.WEBPAGE_START_SCRIPT}"
      }
    }
  }
}
