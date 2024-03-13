# Zlang
A compiled esoteric programming langauge designed to resemble the popular slang of Gen Z.

## Installing / Getting started

### Setup Linux remote environment in VS Code
This step can be skipped if you are already developing with Linux natively.
\
\
Install [Multipass](https://multipass.run/install).
\
\
Create an SSH keypair. To generate a new key pair, run this command:
```
ssh-keygen -t rsa
```
Take note of the location of the generated id_rsa.pub file.
\
\
Copy and paste the text below into a file called vscode.yaml. Replace `<public key>` with the key found in id_rsa.pub.
```
groups:
  - vscode
runcmd:
  - adduser ubuntu vscode
ssh_authorized_keys:
  - ssh-rsa <public key>
```
Open a terminal in the same location as this file, and launch a new instance referencing this cloud-init file:
```
multipass launch --cloud-init vscode.yaml
```
Take note of its IP address by running multipass list.
\
\
Install the "Remote – SSH" VS Code extension.
\
\
From the extension, click “Connect to Host”, then “Add New SSH Host”.
\
\
Type in `ssh ubuntu@<ip address>` where `<ip address>` is replaced with the IP address of the instance that we noted down earlier.
### Install dependencies
Make sure gcc is up to date.
```
sudo apt-get update
```
Install nasm.
```
sudo apt install nasm
```
Install cmake.
```
sudo apt install cmake
```
