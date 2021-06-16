#!/bin/bash

clear 

echo -e "
+--------------------+
|      Packages      |
+--------------------+
| Visual Studio Code |
| Discord            |
| Git Kraken         |
| Vim                |
| -                  |
| Virtualbox Guest   |
| Build Essential    |
| Manpages Dev       |
| CCMake             |
| CMake              |
| G++                |
+--------------------+
"

PS3='Installer Options: '
options=("Install" "Update", "Visual Studio Code Extensions" "Exit")
select opt in "${options[@]}"
do
    case $opt in
        "Install")
            read -r -p "Are you sure you want to continue? [Y/N] " response
			if [[ "$response" =~ ^([yY][eE][sS]|[yY])$ ]]
			then
				#tools
			    sudo apt update
                sudo apt install snapd
                sudo apt install software-properties-common apt-transport-https wget libcurl3 vim guake
                sudo apt install build-essential manpages-dev ccmake cmake g++ valgrind

			    #vscode
			    wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -
			    sudo add-apt-repository "deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main"
				sudo apt install code

                #kraken
                sudo snap install gitkraken

                #discord
                sudo snap install discord

                #vbox extensions
                sudo apt-get install virtualbox-guest-additions-iso virtualbox-guest-x11

			else
			    echo "Exit"
			fi
            break
            ;;
        "Update")
            sudo apt update
            sudo snap refresh 
            break
            ;;
        "Visual Studio Code Extensions")
            #vscode extensions
            sudo code --install-extensions ms-vscode.cpptools formulahendry.code-runner esbenp.prettier-vscode donjayamanne.git-extension-pack
            break
            ;;
        "Exit")
            break
            ;;
        *) echo "Invalid Operation $REPLY";;
    esac
done

