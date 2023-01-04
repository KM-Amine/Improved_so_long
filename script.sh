
COMMIT=$(echo "----commit at date : $(date)-----")

bash ~/nor.sh ./**/.c ./**/.h
echo $COMMIT
git add .
git commit -m "$COMMIT" #> /dev/null