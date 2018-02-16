pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh 'tup generate build.sh'
        sh 'build.sh'
      }
    }
    stage('Checks') {
      steps {
      }
    }
    stage('Test') {
      steps {
      }
    }
    stage('Archive') {
      steps {
      }
    }
    stage('Deploy') {
      steps {
      }
    }
    post {
      always {
        cleanWs()
      }
    }
  }
}
