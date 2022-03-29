<h2>OVERVIEW</h2>
<h3><em>(Requirements)</em></h3>
<p>The game will contain the following components:</p>
<ul>
<li>Player - entity that represents a human player</li>
<li>Timer - timer that will be set and reset for each given word as well as used to trigger game over when it reaches 0</li>
<li>WordList - data structure that will maintain a list of words to be given to the player</li>
<li>wordDirectory - a file that will be used to store a directory of words and to fetch and copy the words to fill the word list</li>
</ul>
<p>Other in-game data will also be kept:</p>
<ul>
<li>word - current word that will be hidden and scrambled from the player until it is deciphered</li>
<li>score - total player score</li>
<li>points - a specific word's point value</li>
<li>letterCount - the amount of letters in each word used to calculate each word's point value</li>
</ul>
<p>Points for each word will be calculated as follows: <em>points = letterCount x 100 </em> </p><br>
<h3><em>(Tools)</em></h3>
<p>&emsp;This game will be written in C++.</p><br>
<h3><em>(Design)</em></h3>
&emsp;<em>(General)</em><br>&emsp;----------<br><br>
<em>
<ol>
<li>Display game title</li>
<li>Display the following selection menu:<br>
<ol>
	<em><li><em>Play</em></li></em>
	<em><li><em>Quit</em></li></em>
</ol>
<li>Prompt user to select Play or Quit</li>
<li>WHILE user did not select Quit:</li>
<ul>
<li>Run game</li>
<li>Prompt user to play again:(1. Play, 2. Quit)</li>
</ul>
<li>End program</li>
</ol>
<br>
&emsp;<em>(Inside the game)</em><br>&emsp;------------------<br><br>
<ol>
	<li>Declare game data:<br>
	Player, WordList, Timer, score, letterCount, points</li>
	<li>Fill word list</li>
	<li>WHILE player has not lost(Timer = 0) or quit:</li>
	<ul>
		<li>Retrieve a word from the word list</li>
		<li>Scramble word and give to player to solve</li>
		<li>Set timer</li>
		<li>Prompt player to solve(unscramble) and type correct word:</li>
		<li>WHILE word is not solved:<br> > Prompt user to type again:</li>
		<li>Calculate and give points</li>
	</ul>
	<li>End game</li>
</ol>
</em>
