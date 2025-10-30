package com.kdill;

public class CounterThread extends Thread {

  private Counter counter;
  private int iters;

  public CounterThread(Counter counter, int iterations) {
    this.counter = counter;
    this.iters = iterations;
  }

  @Override
  public void run() {
    for (int i = 0; i < iters; i++) {
      counter.increment();
    }

    System.out.println("Thread completed iters=" + this.iters);
  }
}
