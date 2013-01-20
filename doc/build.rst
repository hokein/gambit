For developers: Building Gambit from source
===========================================

This section covers instructions for building Gambit from source.
This is for those who are interested in developing Gambit, or who
want to play around with the latest features before they make it
into a pre-compiled binary version.  

This section requires at least some familiarity with programming.
Most users will want to stick with binary distributions; see
:ref:`section-downloading` for how to get the current version for
your operating system.

General information
-------------------

Gambit uses the standard autotools mechanism for configuring and building.
This should be familiar to most users of Un*ces and MacOS X.  

If you are building from a source tarball, 
you just need to unpack the sources, change directory to the top level
of the sources (typically of the form gambit-0.yyyy.mm.dd), and do the
usual ::

  ./configure
  make
  sudo make install

Command-line options are available to modify the configuration process;
do `./configure --help` for information.  

By default Gambit will be installed in /usr/local.  You can change this
by replacing configure step with one of the form

./configure --prefix=/your/path/here

.. note::
  The graphical interface relies on external calls to other
  programs built in this process, especially for the computation of
  equilibria.  It is strongly recommended that you install the Gambit
  executables to a directory in your path!


Building from git repository
----------------------------

If you want to live on the bleeding edge, you can get the latest
version of the Gambit sources from the Gambit repository on
github.com, via ::

  git clone git://github.com/gambitproject/gambit.git
  cd gambit

After this, you will need to set up the build scripts by executing ::

  aclocal
  libtoolize
  automake --add-missing
  autoconf

For this, you will need to have automake, autoconf, and libtool2
installed on your system.

At this point, you can then continue with the configuration and build
stages as in the previous section.


Supported compilers
-------------------

Currently, gcc is the only compiler supported.  The version of gcc needs
to be new enough to handle templates correctly.  The oldest versions
of gcc known to compile Gambit are 3.4.6 (Linux, Ubuntu) and 3.4.2 (MinGW for Windows, Debian stable).

If you wish to use another compiler, the most likely stumbling block is
that Gambit uses templated member functions for classes, so the compiler
must support these.  (Version of gcc prior to 3.4 do not, for example.)

For 64-bit users
----------------

The program gambit-enumpoly does not compile on 64-bit systems.  A new
version of that program is being developed.  It is currently being distributed
separately on the Gambit website.  In the meanwhile, to compile the other
programs in Gambit, 64-bit users should add the switch --disable-enumpoly
to the configuration step, e.g. ::
  
  ./configure --disable-enumpoly [other options here]


For Windows users
-----------------

For Windows users wanting to compile Gambit on their own, you'll need
to use either the Cygwin or MinGW environments.  We do compilation and
testing of Gambit on Windows using MinGW, which can be gotten from
`<http://www.mingw.org>`_.
We prefer MinGW over Cygwin because MinGW will create native Windows
applications, whereas Cygwin requires an extra compatibility layer.


For OS X users
--------------

OS X users should being by following the Un*x/Linux instructions above.
This will create the command-line tools, and the graphical interface
binary called `gambit`.  This graphical interface binary requires the
X server to run correctly.

For a more native OS X experience, after completing the Un*x/Linux
instructions, additionally issue the command ::

  make osx-bundle

This will create a directory Gambit.app with the graphical interface
in an application bundle.  This bundle can then be copied (e.g., to
/Applications) and used like any other OS X application.

Depending on which version of OS X you use, the version of wxWidgets
that comes bundled may not be new enough to meet Gambit's requirements.
The version that shipped with OS X Tiger, for instance, is not.
If you need to build wxWidgets yourself (see below),
be sure to tell the ./configure step where to find the version you built
by using the --with-wx-prefix parameter.  For example, if you install
wxWidgets into /usr/local (the default when you build it), configure
Gambit with ::

  ./configure --with-wx-prefix=/usr/local


The graphical interface and wxWidgets
-------------------------------------

Gambit requires wxWidgets version 2.8.0 or higher for the
graphical interface.  See the wxWidgets website at
`<http://www.wxwidgets.org>`_
to download this if you need it.  Packages of this should be available
for most Un*x users through their package managers (apt or rpm).  Note
that you'll need the appropriate -dev package for wxWidgets to get the
header files needed to build Gambit.

Un*x users, please note that Gambit at this time only supports the
GTK port of wxWidgets, and not the Motif/Lesstif or the Universal ports.
Neither of the latter ports support drag-and-drop features, which are
heavily used in the graphical interface.

If wxWidgets it isn't installed in a standard place (e.g., /usr or
/usr/local), you'll need to tell configure where to find it with the
--with-wx-prefix=PREFIX option, for example::

  ./configure --with-wx-prefix=/home/mylogin/wx

Finally, if you don't want to build the graphical interface, you
can either (a) simply not install wxWidgets, or (b) pass the argument
--disable-gui to the configure step, for example, ::

  ./configure --disable-gui

This will just build the command-line tools, and will not require
a wxWidgets installation.

Gambit repository Information
-----------------------------
Gambit project now hosts on github, `here <https://github.com/gambitproject/gambit>`_ is project page.

You can grab the lastest source code
(use git clone command) from following url::

  https://github.com/gambitproject/gambit.git

Gambit project follows the style of workflow described in gitworkflows manpage::

  http://www.kernel.org/pub/software/scm/git/docs/gitworkflows.html

There are two main branch on gambit repository:

  1. master branch
      This branch is the main dev-branch, you can regard it as upstream branch.
  2. maint branch
      This branch tracks the commits that should go into the next release. But
      at the moment, maint isn't really actively used insofar as a full new relase
      is planned "soon."

You can submit issue or report bugs through opening an issue on gambit
project github repository::

  1. Go to issue page:
       https://github.com/gambitproject/gambit/issues?state=open
  2. Click new issue button to create an issue.
  3. Described the details of the issue and then click "Submit new issue" button.
