## Configuration
~~~powershell
## show all configuration
$ git config --global -l
## show global configuration
$ git config -l
~~~

```powershell
## setup global configuration
git config --global user.name "Your Name"
git config --global user.email youremail@email

## setup local configuration
git config core.pager cat
git config --unset core.pager

## multiple configuration
git config core.editor vi
git config --add core.editor emacs
git config --unset-all core.editor
```

## Basic Local Commands
```powershell
git init

## or from remote
git clone url.git
## the above is equivalent to 
git init ; git pull url.git
```


```powershell
git add filename
git add -A
git add .; git add -u
```

```powershell
git commit -m "message"
``` 

```powershell
git status
```

```powershell
git log --oneline
git shortlog
git log HEAD^^..HEAD
git log --graph --oneline --decorate
git log --after="yesterday"
git log -- README.md
```

```powershell
git checkout -b new
## which is same as 
git branch new
git checkout new
```

```powershell
git merge 
git merge --abort
```

## Remote Collaborations
```powwershell
## remote 
### check stored remote repos
git remote -v
## add remote address
git remote add origin repos.git


## git fetch
git fetch origin
git fetch origin master
git fetch origin --depth=2
### see the difference
git log --oneline master..origin/master
git log origin/master --after="yesterday"
git branch -r

## git pull
git pull <remote>
## the above is equal to:
git fetch <remote>; git merge origin/<remote-branch>

## sometimes use
git pull --rebase <remote> 
## NOT recommend on our repos, too dirty
```
```powershell
git push origin
## to make it work, you have to git config push.default
```

```powershell
git config --global push.default matching
```
It means ```git push``` will push all your local branches to the ones with the same name on the remote. This makes it easy to accidentally push a branch you didn't intend to.

Or
```powershell
git config --global push.default 
```


```powershell
git config --global push.default simple
``` 
It means ```git push``` will push only the current branch to the one that git pull would pull from, and also checks that their names match. This is a more intuitive behavior, which is why the default is getting changed to this.

In general, we can use:

```powershell
## to push local branch_name to remote branch_name
git push origin branch_name

## to push current branch_name to remote branch_name
git push origin HEAD:branch_name
```



