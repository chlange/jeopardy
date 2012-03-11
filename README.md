Jeopardy
========

* Author:	Christian Lange (<chlange@htwg-konstanz.de><Christian_Lange@hotmail.com>)
* Date:		11. March 2012
* Version:	0.9.6 experimental
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
* choose own key to answer (Press key on game field to check functionality)
* right click context menu including
	* random generator to pick random user (Press "r" on game field for same functionality)
	* load/save game state
	* player name and points editor
	* early round ending option
	* round reset
* automated game state backup after each answer 
	* backups can be found in gameStates/backups/
	* backups ordered by round and unix timestamp
* formatted text, sound, images and videos as answer 
	* see answers/1.jrf or wiki for further instructions
	* images and videos will be resized if too big
	* sound and videos will stop after 30 seconds (normal answer time)
	* Press Shift to restart sound or video
* double jeopardy questions 
	* see answers/1.jrf or wiki for further instructions

Todo
----

* smoother design
* ...little here and there

Software used
-------------

* gcc 4.4.3
* Qt 4.6.2
* phonon

Install
-------

	wget https://github.com/chlange/jeopardy/tarball/v0.9.6e
	tar xfv v0.9.6e
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
