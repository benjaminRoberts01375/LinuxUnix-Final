# LinuxUnix-Final
 <h1>Purpose:</h1>
<p>Designed to help with computer ticketing systems by allowing traditional users to adjust the 
	status and comments about a stored computer, while letting admins create the structure for 
	the computers to exist in. This works by linking CSV files together so that a filling 
	structure is created.</p>
	
<h1>Usage:</h1>
<h3>Upon Boot:</h3>
<h4>Users:</h4>
<p>The ticketing system works for two different users, sudo and not. When not run as sudo, the
	user is not allowed to edit the file structure, but is allowed to change the status and comment
	of a computer, as well as navigating through the structure. This is meant for someone to insert
	a problem with a given computer.</p>
<p>However, when the program is run as sudo, the ability to create, destroy, and edit computers and
	folders is allowed, giving admins the ability to maintain their structure. Additionally, since
	this is all done with CSV files, they can be brought into a third-party program if so desired.</p>
<h4>Arguments:</h4>
<p>The program accepts a few arguments:</p>
<ul>
	<li>-v               Verbose boot. Enables logging in the console.</li>
	<li>-h               Help. Instead of running the entire program, the various arguments are put on screen.</li>
	<li>-o [FILENAME]    Open. Allows the user to open any CSV file within the current folder, not just the default one. The extension .csv is optional when running with this argument. </li>
</ul>
<h3>Up and Running:</h3>
<p>Once the program is running, options will be shown on screen. Most often, there are numbers 
	available, such as on the main menu where there are three options. The user is to type the 
	corresponding number when applicable. However, there are rare instances where the user must 
	insert the name of what they're wishing to adjust, such as a computer's full name.</p>
	
<h4>Logging</h4>
<p>The program logs its actions as they happen, from opening a screen, to any edit or change to the 
	CSV file structure, even if verbose mode is not enabled. The log is saved to the current folder
	in the output.txt file. This allows the program to be run in multiple configurations.</p>
	
<h1>Compile:</h1>
<p>There are a few options available with the current make file:</p >
<ol>
	<li>make run – Creates the console library and runs the program. </li>
	<li>make install – Installs the program to be called from the console.</li>
	<li>make clean – Clears out the created library files.</li>
	<li>make remove – Removes the install from the computer.</li>
</ol>
