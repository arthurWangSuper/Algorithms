// leetcode 1195 Fizz Buzz Multithreaded
// Write a program that outputs the string representation of numbers from 1 to n, however:

// If the number is divisible by 3, output “fizz”.
// If the number is divisible by 5, output “buzz”.
// If the number is divisible by both 3 and 5, output “fizzbuzz”.
// For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

// Suppose you are given the following code:
/*
* class FizzBuzz {
*   public FizzBuzz(int n) { ... }               // constructor
*   public void fizz(printFizz) { ... }          // only output "fizz"
*   public void buzz(printBuzz) { ... }          // only output "buzz"
*   public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
*   public void number(printNumber) { ... }      // only output the numbers
* }
*/
/*
* Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:
*
* Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
* Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
* Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
* Thread D will call number() which should only output the numbers.
* Solution:

* 4 Semaphores
*/
#include <iostream>
#include <condition_variable>
#include <mutex>
#include <functional>

using namespace std;

class sem{
    public:
        sem():flag(true){}
        inline void wait(){
            unique_lock<mutex> lock(mux);
            cv.wait(lock,[=]{return flag;});
        }
        inline void notify(){
            unique_lock<mutex> lock(mux);
            flag = true;
            cv.notify_one();
        }
    private:
        mutex mux;
        condition_variable cv;
        bool flag = false;
};

class FizzBuzz{
public:
      FizzBuzz(int n):n(n) {}               // constructor
      void fizz(function<void(int)> printFizz) {
            for(int i = 3;i<=n;i+=3)
            { 
                s3.wait();
                printFizz(i);
                sn.wait();
            }
      }  // only output "fizz"
      void buzz(function<void(int)> printBuzz) {
            for(int i = 5;i<=n;i+=5)
            { 
                s5.wait();
                printBuzz(i);
                sn.wait();
            }
      }  // only output "buzz"
      void fizzbuzz(function<void(int)> printFizzBuzz) {
            for(int i = 15;i<=n;i+=15)
            { 
                s15.wait();
                printFizzBuzz(i);
                sn.wait();
            }
      }  // only output "fizzbuzz"
      void number(function<void(int)> printNumber) {   
            for(int i=i;i<=n;i++){
                if(i%15==0){ s15.notify();sn.wait();}
                else if(i%5==0) {s5.notify();sn.wait();}
                else if(i%3 == 0) {s3.notify();sn.wait();}
                else printNumber(i);
            }
      } // only output the numbers
private:
    int n;
    sem s3;
    sem s5;
    sem s15;
    sem sn;
};