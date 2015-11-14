# C Halma Game

## Contribute

### Files

#### Text file "settings"

All text files have to be in [UTF-8](https://en.wikipedia.org/wiki/UTF-8) (without BOM) encoding (generally UTF-8 on GNU/Linux and ISO 8859-15 on MS Windows) and LF character newline (sometime called UNIX newline/endline) (Windows generally used CRLF).
Unfortunately, by default some text editors save with the same encoding and character newline of your OS.

An empty line must be at the end of text files.
The aim is readability with `cat file`.

##### Configuring text file "settings"

* In order to force to use UTF-8 and LF for this project in Eclipse, do right click on the project in "Package Explorer", then "Properties", in the right panel select "Resource", now you are on the right and enough intelligent to find what to change.
* For creating new files with UTF-8 and LF in Geany, go to "Edit" > "Preferences" > "Files" (tab), then choose "Unix (LF)" for line breaks and "UTF-8" as the default encoding.
* For doing the same thing in Qt Creator, go to "Tools" > "Options" > "Text Editor" > "Behavior".

#### Source code

##### Coding style

We use english, so please use it everywhere in the project (messages, function names, doc, etc).

Names of variables, functions/methods, classes and everything else have to be clear, even if the name is a little longer.
You also do not have to forget to create documentation.

Following the [PEP (Python Enhancement Proposal) 20](https://www.python.org/dev/peps/pep-0020/) is a good thing, even if the project does not use the Python language.

##### C/C++ compilation

The project should compile with at least 2 different C/C++ compilers (differente does not mean version number) (like GCC and Clang).

#### Formatted text files

If you need to make a structured document, you should consider [Markdown](https://en.wikipedia.org/wiki/Markdown).
For example, this document uses the Markdown syntax.

For longer texts or presentations, [LaTeX](http://latex-project.org/) and HTML/CSS(/JS) could be good options.

### Git

#### Installation

##### Debian

The above text should also work on derivatives of [Debian](https://www.debian.org/), like [Trisquel](https://trisquel.info/), [gNewSense](http://www.gnewsense.org/) or Ubuntu.

You have to install the git package and its dependencies.
You must have [SuperUser/root](https://en.wikipedia.org/wiki/Superuser) rights, that you can have with `su` or `su command`.
You can use `apt-get install`, `aptitude install` (if [aptitude](https://wiki.debian.org/Aptitude) is installed) or a graphical user interface with [Synaptic](https://wiki.debian.org/Synaptic) (if it is installed).

##### Fedora, CentOS and RHEL

You have to install the git package and its dependencies.
With SuperUser/root rights, you can use `yum install` or a graphical user interface with [Yum Extender](http://www.yumex.dk/) (if it is installed).

##### Microsoft Windows (and ReactOS?) and Apple OS X

Download it on [the official website](http://www.git-scm.com/downloads) and install it.

#### Use

If you do not know how to use it, you must read a documentation (like [the official one](http://www.git-scm.com/doc)).

Use `git status` to check that your modifications will be commited.
You have to pull before push.

git provides only a text shell interface.
However, you can install a graphical user interface for it (like [git-cola](https://git-cola.github.io/) or [gitg](https://wiki.gnome.org/Apps/Gitg/)).

## License and authors

See [LICENSE.md](LICENSE.md) and logs of git for the full list of contributors of the project.

## Tasks to do

* Clarify licensing policy.
* Finish the project
  * Manage 2 to 4 players in main
  * Create a grid automatically
  * Manage winning and game over
  * Print the grid with colors
  *  A progress report, in PDF, with screenshots
* Try to compile and make the program works on more OS (FreeBSD, ReactOS, etc) (only GNU/Linux has been tested currently)
* Search and do TODO

### Ideas

* Reduce tab_2d_char_essential by creating tab_2d_char_plus
* Use macros and inline functions to optimize
* Create a struct for each halma_game_player_choose_move function with a name and a description
* Create an icon
* A graphical user interface
* Compute a score for ranking loosers
* Create a C++ interface
* Packages (deb, rpm, etc)
* Play through the network
