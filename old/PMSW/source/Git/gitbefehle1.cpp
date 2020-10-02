$ git checkout v1^ 				// wechsel zum vorherigen Commit
Note: checking out 'v1^'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b new_branch_name
  
 HEAD is now at 8c32287... Added standard HTML page tags
----------------------------------------------------------------------------------------
 $ git reset HEAD hello.html         // unstage von hello.html (nach add befehl)
Unstaged changes after reset:
M   hello.html
----------------------------------------------------------------------------------------
$ git revert HEAD --no-edit			// Revert Commit (erstellt ein neuer Commit mit 'Revert' als Prefix)
[master 45fa96b] Revert "Oops, we didn't want this commit"
 1 files changed, 1 insertions(+), 1 deletions(-)
$ git hist							// 
* 45fa96b 2011-03-09 | Revert "Oops, we didnt want this commit" (HEAD, master) [Alexander Shvets]
* 846b90c 2011-03-09 | Oops, we didnt want this commit [Alexander Shvets]
* fa3c141 2011-03-09 | Added HTML header (v1) [Alexander Shvets]
* 8c32287 2011-03-09 | Added standard HTML page tags (v1-beta) [Alexander Shvets]
* 43628f7 2011-03-09 | Added h1 tag [Alexander Shvets]
* 911e8c9 2011-03-09 | First Commit [Alexander Shvets]
----------------------------------------------------------------------------------------
$ git tag oops 						// Markiert den Revert Commit mit dem Tag oops
----------------------------------------------------------------------------------------
$ git reset --hard v1				// Setzt den Master Branch zum gewuenschten Commit
HEAD is now at fa3c141 Added HTML header
$ git hist
* fa3c141 2011-03-09 | Added HTML header (HEAD, v1, master) [Alexander Shvets]
* 8c32287 2011-03-09 | Added standard HTML page tags (v1-beta) [Alexander Shvets]
* 43628f7 2011-03-09 | Added h1 tag [Alexander Shvets]
* 911e8c9 2011-03-09 | First Commit [Alexander Shvets]
----------------------------------------------------------------------------------------
$ git hist --all					// Commits werden aber immernoch in der History angezeigt!
									// Wird erst durch Garbage Collector aus History entfernt
* 45fa96b 2011-03-09 | Revert "Oops, we didn't want this commit" (oops) [Alexander Shvets]
* 846b90c 2011-03-09 | Oops, we didnt want this commit [Alexander Shvets]
* fa3c141 2011-03-09 | Added HTML header (HEAD, v1, master) [Alexander Shvets]
* 8c32287 2011-03-09 | Added standard HTML page tags (v1-beta) [Alexander Shvets]
* 43628f7 2011-03-09 | Added h1 tag [Alexander Shvets]
* 911e8c9 2011-03-09 | First Commit [Alexander Shvets]
----------------------------------------------------------------------------------------
$ git tag -d oops				// Löscht den Oops Tag und fuehrt den Garbage Collector aus
Deleted tag 'oops' (was 45fa96b)
$ git hist --all				// Commits wurden geloescht
* fa3c141 2011-03-09 | Added HTML header (HEAD, v1, master) [Alexander Shvets]
* 8c32287 2011-03-09 | Added standard HTML page tags (v1-beta) [Alexander Shvets]
* 43628f7 2011-03-09 | Added h1 tag [Alexander Shvets]
* 911e8c9 2011-03-09 | First Commit [Alexander Shvets]
----------------------------------------------------------------------------------------
$ git add hello.html
$ git commit --amend -m "Add an author/email comment"	// Ersetzt den letzten Commit
[master 6a78635] Add an author/email comment
 1 files changed, 2 insertions(+), 1 deletions(-)
 ----------------------------------------------------------------------------------------
$ mkdir lib				// Ordner erstellen
$ git mv hello.html lib  //move hello.html in lib Ordner
$ git status
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
#   renamed:    hello.html -> lib/hello.html
#
----------------------------------------------------------------------------------------
$ git init
Initialized empty Git repository in /Users/alex/Documents/Presentations/githowto/auto/hello/.git/