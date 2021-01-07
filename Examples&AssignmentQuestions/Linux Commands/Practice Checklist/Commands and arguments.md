Practise5: commands and arguments
1. How many arguments are in this line (not counting the command itself).
touch '/etc/cron/cron.allow' 'file 42.txt' "file 33.txt"
2. Is tac a shell builtin command ?
3. Is there an existing alias for rm ?
4. What is -i option of rm. Create and remove a file to test the -i option.
5. Execute: alias rm='rm -i' . Test your alias with a test file. Does this work as expected ?
6. List all current aliases.
7a. Create an alias called 'city' that echoes your hometown.
7b. Use your alias to test that it works.
8. Execute set -x to display shell expansion for every command.
9. Test the functionality of set -x by executing your city and rm aliases.
10. Execute set +x to stop displaying shell expansion.
11. Remove your city alias.
12. What is the location of the cat and the passwd commands ?
13. Explain the difference between the following commands:
echo
/bin/echo
14. Explain the difference between the following commands:
echo Hello
echo -n Hello
15. Display A B C with two spaces between B and C.
16. Display (do not use spaces) exactly the following output:
4+4		=8
10+14 	=24
17. Use echo to display the following exactly :??\\
Find two solutions with single quotes, two with double quotes and one without quotes.
18. Use one echo command to display three words on three lines.