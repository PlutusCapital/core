
Debian
====================
This directory contains files used to package plutusd/plutus-qt
for Debian-based Linux systems. If you compile plutusd/plutus-qt yourself, there are some useful files here.

## plutus: URI support ##


plutus-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install plutus-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your plutus-qt binary to `/usr/bin`
and the `../../share/pixmaps/plutus128.png` to `/usr/share/pixmaps`

plutus-qt.protocol (KDE)

