./parsetest ./config/parsetest.config
echo "> PARSE TEST START!"
diff ./result/parseTest ./answer/parseTest
if [ $? -eq 0 ] ; then
	echo "Success!"
elif [ $? -eq 1 ] ; then
	echo "Failed!"
else
	echo "Diff_error!"
fi