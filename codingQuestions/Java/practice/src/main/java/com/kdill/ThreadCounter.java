package com.kdill;

import java.util.Random;

import com.kdill.Counter;
import com.kdill.CounterThread;

public class ThreadCounter {

  public static void main(String[] args) {

    Counter count1 = new Counter();

    int threadCount = 12;
    CounterThread[] threads = new CounterThread[threadCount];

    int unthreadedSum = 0;
    Random rnd = new Random();

    for (int i = 0; i < threadCount; i++) {

      int timesToIncrement = rnd.nextInt(1000, 3000);

      System.out.printf("Creating thread[%d] to increment %d times\n",
          i, timesToIncrement);

      threads[i] = new CounterThread(count1, timesToIncrement);
      threads[i].start();

      unthreadedSum += timesToIncrement;

    }

    //wait for threads to complete and join them in main
    try {
      for (CounterThread thread : threads) {
        thread.join();
      }
    } catch (Exception e) {
      e.printStackTrace();
      return;
    }

    //compare the unthreaded sum to the completed threaded sum
    System.out.printf("ThreadCount=%d, Unthreaded=%d\n",
        count1.getCount(), unthreadedSum);


  }

}
