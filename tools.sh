#!/bin/bash

clear 

echo -e "
+---------------------------+
|         Packages          |
+---------------------------+
| Visual Studio Code        |
| Discord                   |
| Git Kraken (Git UI)       |
| Vim (Editor)              |
| Guake (Fast Terminal F12) |
| -                         |
| Virtualbox Guest          |
| Build Essential           |
| Manpages Dev              |
| CCMake                    |
| CMake                     |
| G++                       |
| -                         |
| Git Lens                  |
| MS C++                    |
| Prettier                  |
| Cmake Tools               |
+---------------------------+
"

REQUIRED_PKG="whiptail"
PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG|grep "install ok installed")
echo Checking for $REQUIRED_PKG: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG. Setting up $REQUIRED_PKG."
  sudo apt-get --yes install $REQUIRED_PKG 
fi

if whiptail --yesno "Raf Workspace Installer | This script will install core pkgs for a better workflow, update pkgs and install vscode extensions. This pkg includes C++ tools, valgrind, vim, vscode, vscode with c++ formatting extensions, vbox fixes and other quality of life extensions." 10 100 --defaultno; then
    CHOICE=$(whiptail --menu "Options" 18 100 10 \
    "Install Tools" "Installs Visual Studio Code, Guake and all other tools." \
    "Update" "Update all packages." \
    "Visual Studio Code Extensions" "Adds useful extensions." 3>&1 1>&2 2>&3)
    if [ -z "$CHOICE" ]; then
    echo "No option was chosen (user hit Cancel)"
    else
        echo "The user chose $CHOICE"
        if [[ "$CHOICE" == *"Install Tools"* ]]; then
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
                sudo snap install gitkraken --classic

                #discord
                sudo snap install discord

                #vbox extensions
                #This fixes window size issues on latops and solves performance issues on OSX Lion and higher.
                sudo apt-get install virtualbox-guest-additions-iso virtualbox-guest-x11

			else
			    echo "Exit"
			fi
        elif [[ "$CHOICE" == *"Update"* ]]; then
            sudo apt update
            sudo snap refresh 
        elif [[ "$CHOICE" == *"Visual Studio Code Extensions"* ]]; then
            sudo code --install-extensions ms-vscode.cpptools formulahendry.code-runner esbenp.prettier-vscode donjayamanne.git-extension-pack ms-vscode.cmake-tools twxs.cmake
        fi
    fi
else
  echo "Exit"
fi
