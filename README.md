Jeopardy
========

* Description:	
* Author:	Christian Lange (<chlange@htwg-konstanz.de><Christian_Lange@hotmail.com>)
* Date:		08. Dezember 2011
* Version:	0.9.4 experimental version 4
* Github:	https://github.com/chlange/jeopardy
* Homepage:	http://ganz-sicher.net/chlange
* License:	New BSD License (3-clause BSD license)

Description
-----------

* Implementation of well known Jeopardy! quiz show in C++ using Qt library

Features
--------

* up to 9 players
* sound
* colors
* names
* choose own key to answer
* right click context menu including
	* random generator to pick random user
	* load/save game state
	* player name and points editor
	* early round ending option
* automated game state backup after each answer 
	* backups can be found in gameStates/backups/
	* backups ordered by unix timestamp
* formatted text and (if too big) resized images as answer 
	* see answers/1.jrf or wiki for further instructions
* double jeopardy questions 
	* see answers/1.jrf or wiki for further instructions

Todo
----

* smoother design
* ...little here and there

Software used
-------------

* Ubuntu 10.04
* gcc
* Qt 4.6.2
* phonon

Install
-------

	wget https://github.com/chlange/jeopardy/tarball/v0.9.4e4
	tar xfv https://github.com/chlange/jeopardy/tarball/v0.9.4e4
	cd chlange-jeopardy-...
	make
	chmod +x jeopardy
	./jeopardy

Play
----

* Edit answers/round.jrf
	* see answers/1.jrf or wiki for further instructions
* Choose round to play
* Enter names, keys and colors of players
* Select question

Screenshots
-----------

Round choice:

![](http://i.imgur.com/PdzVW.png)

Player input:

![](http://i.imgur.com/kZTJF.png)

Game field: 

![](http://i.imgur.com/TojZ7.png)

Colored game field:

![](http://i.imgur.com/4kwY6.png)

Answer:

![](http://i.imgur.com/hMVrk.png)

Podium:

![](http://i.imgur.com/lIQgj.png)

Bugs? Feature requests? Have some Beer?
------------------------------------------

Don't hesitate to contact me!
