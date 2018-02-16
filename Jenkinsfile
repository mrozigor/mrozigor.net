pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'tup init'
        sh 'tup generate ${env.WORKSPACE}/build.sh'
        sh '${env.WORKSPACE}/build.sh'
      }
    }
    stage('Checks') {
      steps {
        echo 'Checks'
      }
    }
    stage('Test') {
      steps {
        echo 'Test'
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
