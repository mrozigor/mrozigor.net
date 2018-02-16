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
        sh "tar --xz -cvf ${env.WORKSPACE}/server_${env.BUILD_NUMBER}.tar.xz -C ${env.WORKSPACE}/build server"
        sh "cp ${env.WORKSPACE}/server_${env.BUILD_NUMBER}.tar.xz /home/mrozigor/domains/mrozigor.net/builds"
      }
    }
    stage('Deploy') {
      steps {
        sh "kill `cat /home/mrozigor/.mrozigor_net.pid` || true"
        sh "cp ${env.WORKSPACE}/build/server /home/mrozigor/domains/mrozigor.net/"
        sh "/home/mrozigor/check_mrozigor_net_running"
      }
    }
  }
  post {
    always {
      cleanWs()
    }
  }
}
