package com.kdill;

/**
 * INCOMPLETE FILE
 */

import java.util.LinkedList;
import java.util.Queue;

/**
 * ConsumerProducer: One thread creates, one thread consumes and uses.
 * SINGULAR consumer and producer. Can expand later.
 * Consumer class spins waiting on the queue of tasks, executing each in order.
 * Producer class spins when queue is full, trying to push a task on.
 */
public class ConsumerProducer {

  private static int sumOfConsumed;

  private static final int QUEUE_CAPACITY = 100;
  private static final Queue<Integer> taskQueue = new LinkedList<>();

  public static void main(String[] args) {

    sumOfConsumed = 0;

    // Create a consumer first, then some subset of producers.
    Thread consumeThread = new Thread(new Consumer());
    Thread produceThread = new Thread(new Producer());

    try {
      consumeThread.start();

    } catch (Exception e) {
      e.printStackTrace();
    }

  }

  static class Consumer implements Runnable {

    // What do I want the consumer to do?
    // add into a sum variable? print what it grabbed?
    public void run() {

      int value = 0;

      // forever thread
      while (true)

        System.out.println("Consuming: " + value);

    }
  }

  static class Producer implements Runnable {

    public void run() {

    }
  }

}
