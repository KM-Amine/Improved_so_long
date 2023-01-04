
COMMIT=$(echo "----commit at date : $(date)-----")
echo $COMMIT
fnorm ./**/*.c
git add .
git commit -m "$COMMIT"