<h2>OVERVIEW</h2>
<em>(Requirements)</em>
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
<p>Points for each word will be calculated as follows: <em>points = letterCount x 100 </em> </p>
<br>
<em>(Tools)</em>
<br>
<p>This game will be written in C++.</p>

