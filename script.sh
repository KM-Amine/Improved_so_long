
COMMIT=$(echo "----commit at date : $(date)-----")

echo $COMMIT
git add .
git commit -m "$COMMIT"