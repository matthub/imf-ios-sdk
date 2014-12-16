#git tag -a 0.1 -m 'my version 0.1 $(date)'
#git push --tags
git add --all .
git commit -m "generated files on `date +'%Y-%m-%d %H:%M:%S'`";
git push origin master
#pod repo update