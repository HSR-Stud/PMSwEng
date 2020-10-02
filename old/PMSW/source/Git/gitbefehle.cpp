$ git status			// nichts wurde geaendert
# On branch master
nothing to commit (working directory clean)
----------------------------------------------------------------------------------------
$ git status	// es wurde hello.html veraendert
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#   modified:   hello.html
#
no changes added to commit (use "git add" and/or "git commit -a")
----------------------------------------------------------------------------------------
$ git add hello.html	// hello.html staged und dann git status
$ git status
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
#   modified:   hello.html
#
----------------------------------------------------------------------------------------
$ git status			// hello.html geaendert nach dem staging und danach git status
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
#   modified:   hello.html
#
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#   modified:   hello.html
#
----------------------------------------------------------------------------------------
$ git commit -m "Added standard HTML page tags"	 // commit und git status
[master 8c32287] Added standard HTML page tags
 1 files changed, 3 insertions(+), 1 deletions(-)
$ git status
# On branch master
# Changes not staged for commit:
#   (use "git add <file>..." to update what will be committed)
#   (use "git checkout -- <file>..." to discard changes in working directory)
#
#   modified:   hello.html
#
no changes added to commit (use "git add" and/or "git commit -a")
----------------------------------------------------------------------------------------
$ git log --pretty=oneline		
fa3c1411aa09441695a9e645d4371e8d749da1dc Added HTML header
8c3228730ed03116815a5cc682e8105e7d981928 Added standard HTML page tags
43628f779cb333dd30d78186499f93638107f70b Added h1 tag
911e8c91caeab8d30ad16d56746cbd6eef72dc4c First Commit
----------------------------------------------------------------------------------------
$ git checkout 911e8c9 			// zu einem aelteren Commit wechseln
Note: checking out '911e8c9'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b new_branch_name

HEAD is now at 911e8c9... First Commit
----------------------------------------------------------------------------------------
$ git checkout master 			// zum aktuellsten commit wechseln
Previous HEAD position was 911e8c9... First Commit
Switched to branch 'master'
----------------------------------------------------------------------------------------
git tag v1 						// dem aktuellen Commit den Tag v1 geben
