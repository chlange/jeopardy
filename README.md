Jeopardy
========

* Description:	
* Author:	Christian Lange (<chlange@htwg-konstanz.de><Christian_Lange@hotmail.com>)
* Date:		26. November 2011
* Version:	0.9.3 experimental
* Github:	https://github.com/chlange/jeopardy
* Homepage:	http://ganz-sicher.net/chlange
* License:	New BSD License (3-clause BSD license)

Description
-----------

* Implementation of well known Jeopardy! quiz show in C++ using Qt library

Features
--------

* 3 players
* sound
* colors
* names
* right click context menu including
	* load/save game state
	* player name and points editor
	* early round ending option
* automated game state backup after each answer 
	* backups can be found in gameStates/backups/
	* backups ordered by unix timestamp
* formatted text and images as answer 
	* see answers/1.jrf for further instructions
* double jeopardy questions 
	* see answers/1.jrf for further instructions

Todo
----

* player can choose key
* add fourth player for final
* dynamic resize of layout
* smoother design
* ...little here and there

Software used
-------------

* Ubuntu 10.04
* gcc
* Qt 4.6.2

Install
-------

	wget https://github.com/chlange/jeopardy/tarball/v0.9.3
	tar xfv v0.9.3
	cd chlange-jeopardy-...
	make
	chmod +x jeopardy
	./jeopardy

Play
----

* Choose round to play
* Enter names of players
* Select question
* Use 	A for player 1
	G for player 2
	K for player 3

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

Bugs? Feature request? Have some Beer?
------------------------------------------

Don't hesitate to contact me!
