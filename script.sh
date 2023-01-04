
COMMIT=$(echo "----commit at date : $(date)-----")

bash ~/nor.sh ./**/.c ./**/.h
echo $COMMIT
fnorm ./**/*.c
git add .
git commit -m "$COMMIT"