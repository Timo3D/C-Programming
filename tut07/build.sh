#!/bin/bash

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o test0 test0.c utils.c

./test0 < input-test0-0.txt > actual-output-test0-0.txt
diff actual-output-test0-0.txt expected-output-test0-0.txt --strip-trailing-cr
cat actual-output-test0-0.txt > actual-output.txt

./test0 < input-test0-1.txt > actual-output-test0-1.txt
diff actual-output-test0-1.txt expected-output-test0-1.txt --strip-trailing-cr
cat actual-output-test0-1.txt >> actual-output.txt

./test0 < input-test0-2.txt > actual-output-test0-2.txt
diff actual-output-test0-2.txt expected-output-test0-2.txt --strip-trailing-cr
cat actual-output-test0-2.txt >> actual-output.txt

./test0 < input-test0-3.txt > actual-output-test0-3.txt
diff actual-output-test0-3.txt expected-output-test0-3.txt --strip-trailing-cr
cat actual-output-test0-3.txt >> actual-output.txt

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o test1 test1.c utils.c

./test1 < input-test1-4.txt > actual-output-test1-4.txt
diff actual-output-test1-4.txt expected-output-test1-4.txt --strip-trailing-cr
cat actual-output-test1-4.txt >> actual-output.txt

./test1 < input-test1-5.txt > actual-output-test1-5.txt
diff actual-output-test1-5.txt expected-output-test1-5.txt --strip-trailing-cr
cat actual-output-test1-5.txt >> actual-output.txt

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o test2 test2.c utils.c

./test2 < input-test2-6.txt > actual-output-test2-6.txt
diff actual-output-test2-6.txt expected-output-test2-6.txt --strip-trailing-cr
cat actual-output-test2-6.txt >> actual-output.txt

./test2 < input-test2-7.txt > actual-output-test2-7.txt
diff actual-output-test2-7.txt expected-output-test2-7.txt --strip-trailing-cr
cat actual-output-test2-7.txt >> actual-output.txt

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o test3 test3.c utils.c

./test3 < input-test3-8.txt > actual-output-test3-8.txt
diff actual-output-test3-8.txt expected-output-test3-8.txt --strip-trailing-cr
cat actual-output-test3-8.txt >> actual-output.txt

./test3 < input-test3-9.txt > actual-output-test3-9.txt
diff actual-output-test3-9.txt expected-output-test3-9.txt --strip-trailing-cr
cat actual-output-test3-9.txt >> actual-output.txt

./test3 < input-test3-10.txt > actual-output-test3-10.txt
diff actual-output-test3-10.txt expected-output-test3-10.txt --strip-trailing-cr
cat actual-output-test3-10.txt >> actual-output.txt

./test3 < input-test3-11.txt > actual-output-test3-11.txt
diff actual-output-test3-11.txt expected-output-test3-11.txt --strip-trailing-cr
cat actual-output-test3-11.txt >> actual-output.txt

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o test4 test4.c utils.c

./test4 < input-test4-12.txt > actual-output-test4-12.txt
diff actual-output-test4-12.txt expected-output-test4-12.txt --strip-trailing-cr
cat actual-output-test4-12.txt >> actual-output.txt

./test4 < input-test4-13.txt > actual-output-test4-13.txt
diff actual-output-test4-13.txt expected-output-test4-13.txt --strip-trailing-cr
cat actual-output-test4-13.txt >> actual-output.txt

./test4 < input-test4-14.txt > actual-output-test4-14.txt
diff actual-output-test4-14.txt expected-output-test4-14.txt --strip-trailing-cr
cat actual-output-test4-14.txt >> actual-output.txt

./test4 < input-test4-15.txt > actual-output-test4-15.txt
diff actual-output-test4-15.txt expected-output-test4-15.txt --strip-trailing-cr
cat actual-output-test4-15.txt >> actual-output.txt

./test4 < input-test4-16.txt > actual-output-test4-16.txt
diff actual-output-test4-16.txt expected-output-test4-16.txt --strip-trailing-cr
cat actual-output-test4-16.txt >> actual-output.txt

./test4 < input-test4-17.txt > actual-output-test4-17.txt
diff actual-output-test4-17.txt expected-output-test4-17.txt --strip-trailing-cr
cat actual-output-test4-17.txt >> actual-output.txt

gcc -Wall -Werror -Wextra -Wconversion -Wstrict-prototypes -pedantic-errors -std=c11 -o third_largest third_largest.c utils.c

./third_largest < input-third_largest-18.txt > actual-output-third_largest-18.txt
diff actual-output-third_largest-18.txt expected-output-third_largest-18.txt --strip-trailing-cr
cat actual-output-third_largest-18.txt >> actual-output.txt

./third_largest < input-third_largest-19.txt > actual-output-third_largest-19.txt
diff actual-output-third_largest-19.txt expected-output-third_largest-19.txt --strip-trailing-cr
cat actual-output-third_largest-19.txt >> actual-output.txt

./third_largest < input-third_largest-20.txt > actual-output-third_largest-20.txt
diff actual-output-third_largest-20.txt expected-output-third_largest-20.txt --strip-trailing-cr
cat actual-output-third_largest-20.txt >> actual-output.txt

./third_largest < input-third_largest-21.txt > actual-output-third_largest-21.txt
diff actual-output-third_largest-21.txt expected-output-third_largest-21.txt --strip-trailing-cr
cat actual-output-third_largest-21.txt >> actual-output.txt

./third_largest < input-third_largest-22.txt > actual-output-third_largest-22.txt
diff actual-output-third_largest-22.txt expected-output-third_largest-22.txt --strip-trailing-cr
cat actual-output-third_largest-22.txt >> actual-output.txt

./third_largest < input-third_largest-23.txt > actual-output-third_largest-23.txt
diff actual-output-third_largest-23.txt expected-output-third_largest-23.txt --strip-trailing-cr
cat actual-output-third_largest-23.txt >> actual-output.txt

diff actual-output.txt expected-output.txt --strip-trailing-cr