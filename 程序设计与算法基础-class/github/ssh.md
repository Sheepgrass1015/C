sh-3.2# ssh-keygen -t rsa -C "361677187@qq.com"
Generating public/private rsa key pair.
Enter file in which to save the key (/var/root/.ssh/id_rsa): 
/var/root/.ssh/id_rsa already exists.
Overwrite (y/n)? y
Enter passphrase (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /var/root/.ssh/id_rsa
Your public key has been saved in /var/root/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:FyBZlF7cj3fDvycuvz53N4Fckxe+bNsq3w6+CY1+Rho 361677187@qq.com
The key's randomart image is:
+---[RSA 3072]----+
|      .++o .     |
|      ....o .  . |
|       . ..  oo o|
|        .  .. oBo|
|        S . ..+.*|
|         .  E=.=.|
|            o++ =|
|           .+o=B*|
|            .X@OB|
+----[SHA256]-----+
key:495574lyx

apple@liuyuxindeMacBook-Air ~ % ssh -T git@github.com
The authenticity of host 'github.com (20.205.243.166)' can't be established.
ED25519 key fingerprint is SHA256:+DiY3wvvV6TuJJhbpZisF/zLDA0zPMSvHdkr4UvCOqU.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'github.com' (ED25519) to the list of known hosts.的、
Enter passphrase for key '/Users/apple/.ssh/id_rsa': 
Hi Sheepgrass1015! You've successfully authenticated, but GitHub does not provide shell access.

apple@liuyuxindeMacBook-Air ~ % git config --global user.name"username"
apple@liuyuxindeMacBook-Air ~ % git config --global user.email"email"
apple@liuyuxindeMacBook-Air ~ % git config user.name
Sheepgrass1015
apple@liuyuxindeMacBook-Air ~ % git config user.email
361677187@qq.com
apple@liuyuxindeMacBook-Air ~ % 