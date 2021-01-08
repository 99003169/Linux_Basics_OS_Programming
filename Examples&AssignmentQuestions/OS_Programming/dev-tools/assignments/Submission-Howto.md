# Steps

## Gitlab account && project
* Create a gitlab account with your personal id
* Create a new project with the name `linux-prog-assignments`
  * Please make this as private repository
  * You can opt for initialize with README

## Install GIT
```
sudo apt install git
git config --global user.name "Your Name"
git config --global user.email "username@domain.com"
```

## Using git command line
* Clone the git repo to your local machine
  ```
  git clone https://gitlab.com/xxxxx/linux-prog-assignments
  ```
* Switch to cloned repo using cd 
* Copy the your assignment files manually, preferably with cp commands
* Follow these steps
  ```
  git add <your files>
  git commit -m "Added Assignment-1"
  git push -u origin master
  ```
* Verify uploaded files on gitlab web interface


