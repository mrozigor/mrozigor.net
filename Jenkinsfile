pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh "tup init"
        sh "tup generate ${env.WORKSPACE}/build.sh"
        sh "${env.WORKSPACE}/build.sh"
      }
    }
    stage('Checks') {
      steps {
        sh "cppcheck --library=${env.WORKSPACE}/std.cfg --suppress=missingInclude --suppress=*:${env.WORKSPACE}/src/crow.hpp --enable=all --inconclusive --template=\"{file},{line},{severity},{id},{message}\" ${env.WORKSPACE}/src 2> cppcheck.txt"
        step([$class: 'WarningsPublisher', parserConfigurations: [[parserName: 'cpp', pattern: "cppcheck.txt"]], usePreviousBuildAsReference: true])
        echo "TODO Add Valgrind plugin assoon as it will be available in pipeline"
      }
    }
    stage('Test') {
      steps {
        echo "TODO Test - add test compilation to tupfile and here execute test exec"
        echo "TODO Execute xUnit publisher etc."
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
  post {
    always {
      cleanWs()
    }
  }
}
