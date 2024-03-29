check=$(find . -type f \( -name \*.c -o -name \*.h -o -name Makefile \) )
		
#enter -q as the argument
#this function is a simplified operaction from the one below
if [ $# == 1 ] && [ $1 == "-q" ] ; then
    if [ -z "$check" ]; then
				exit
		else
				if [ ! -d ".backup" ]; then

						mkdir .backup						
						for file in ./*.c ./*.h ./Makefile; do
								cp "$file" ./.backup
								echo -e ".\n"
						done						
				else
						for file in ./*.c ./*.h ./Makefile; do

								fileName="$(basename $file)"
								if [ -f ./.backup/$fileName ] ; then
										cmp -s ./$fileName ./.backup/$fileName
										if [ $? == 1 ] ; then
												echo -e ".\n"
												cp $file ./.backup/
										fi
								else
										echo -e ".\n"
										cp $file ./.backup/
								fi
						done
				fi
		fi
#enter main function
elif [ $# == 0 ] ; then
		
    if [ -z "$check" ]; then
				echo "Nothing to backup!"
		else
				if [ ! -d ".backup" ]; then

						echo ".backup doesn't exist...creating a new folder"
						mkdir .backup						
						echo "copying all files to .backup..."
						for file in ./*.c ./*.h ./Makefile; do
								cp "$file" ./.backup
						done
						
				else
						echo "'.backup' folder existed!"
						echo "comparing files in '.backup'..."
						#loop through each file
						for file in ./*.c ./*.h ./Makefile; do

								fileName="$(basename $file)"

								#check if there's already copy in .backup
								if [ -f ./.backup/$fileName ] ; then
										echo "> $fileName already existed in .backup"
										cmp ./$fileName ./.backup/$fileName
										if [ $? == 1 ] ; then
												echo ">> $file changed..."
												cp $file ./.backup/
										else
												echo "> no file changed"
										fi

								#if no copy in .backup yet, make a copy
								else
										echo ">> no $fileName in .backup yet...making copy now"
										cp $file ./.backup/
								fi
						done
				fi
		fi

#enter wrong argument
else
		echo "usage:backup.sh [-q]"
		exit
		
echo ...Backup done...
fi

exit
