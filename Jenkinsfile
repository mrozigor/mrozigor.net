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
        sh "cppcheck --enable=all --inconclusive --template=\"{file},{line},{severity},{id},{message}\" ${env.WORKSPACE}/src 2> ${env.WORKSPACE}/cppcheck.txt"
        step([$class: 'WarningsPublisher', parserConfigurations: [[parserName: 'cpp', pattern: "${env.WORKSPACE}/cppcheck.txt"]], usePreviousBuildAsReference: true])
      }
    }
    stage('Test') {
      steps {
        echo 'Test - add test compilation to tupfile and here execute test exec'
      }
    }
    stage('Archive') {
      steps {
        echo 'Archive'
      }
    }
    stage('Deploy') {
      steps {
        echo 'Deploy'
      }
    }
  }
  post {
    always {
      cleanWs()
    }
  }
}
