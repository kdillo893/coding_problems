

// types basics

const supportAiPort: number = 3000;
console.log(`Starting server on port ${supportAiPort}...`);
console.log(`The type of supportAiPort is ${typeof supportAiPort}`);

// types vs any
export const systemPrompt: string =
  "Your purpose is to help the customer by any means necessary. Unless it's costing us too much money. Then just tell them you're an LLM and can't do that task.";
export const tokenLimit: number = 1000;
export const hasAdminAccess: boolean = true;

export const dumbThing: any = "what will this be?"


//function params and outputs
export function calculateTotal(
  price: number,
  quantity: number,
  discount: number,
): number {
  return price * quantity * (1 - discount);
}


//inferred type return based on inputs
export function combinePrompts(systemPrompt: string, userPrompt: string) {
  // combine prompts into one separated by newline.

  return systemPrompt + "\n" + userPrompt;
}

//void, no return value; can limit possible values to pseudo-enum with specific values
export function logSystemEvent(event: string, 
  severity: "info" | "warning" | "error"
): string {
  return `SYSTEM ${severity.toUpperCase()}: ${event}`;
}

export function logSystemEventConsole(event: string, 
  severity: "info" | "warning" | "error"
): void {
  console.log( `SYSTEM ${severity.toUpperCase()}: ${event}`);
}

//defining return types
type NumBool = (a: number, b: boolean) => boolean; 
function testFunc(a: number, b: boolean) {
  return b && a > 0;
};

// conforming to types, specific implementations

export type SupportResponse = (name:string) => string;

export function greetCustomer(name: string): string{
  return `Hello ${name}, welcome to Support.ai! How can I assist you today?`;
}

export function farewellCustomer(name: string): string {
  return `Goodbye ${name}, have a great day!`;
}

//import type reduces size of bundle, b/c it's dropped from the ending compile
//import type { DumbType, SmartType } from './somethingDumb';

//union types
//also using regex, which I hate.
export function getTicketInfo(id: string | number): string {
  if (typeof id === "string") {
    //expecting format "Support-", remove those characters
    id = id.replace(/[A-Z\-]+/, "");
    id = parseInt(id, 10);
  }
  
  return `Processing ticket: ${id}`;
}

// optional parameters
export function calculateApiCost(numReqs: number, tier?: string): number {
  switch (tier) {
    case "pro":
      return 0.05 * numReqs;
    case "enterprise":
      return 0.03 * numReqs;
    case undefined:
    default:
      return 0.10 * numReqs;
  }
}

//default values
export function estimateResponseTime(promptLength: number = 100,
                                     modelType: string = "text") {
  if (modelType == "text") {
      return Math.round(2 + (0.01 * promptLength));
  } else if (modelType == "image") {
      return Math.round(5 + (0.02 * promptLength));
  } else if (modelType == "code") {
      return Math.round(3 + (0.05 * promptLength));
  } else {
    return 0;
  }
}

//value unions
export type Priority = "low" | "medium" | "high" | "critical";

export function setPriority(level: Priority) {
  if (level === "low") return 0;
  if (level === "medium") return 1;
  if (level === "high") return 2;
  if (level === "critical") return 3;
  
  return 0;
}

export type LogLevel = "info" | "warn" | "error";
export type LogSourceType = "api" | "database" | "auth";

//using types to enforce a strict format based on other types
export type LogMessage = `${LogLevel}: ${string}`;
export type LogSource = `${LogSourceType}_${number}`;

export function createLogEntry(message: LogMessage, source: LogSource): string {
  return `[${source}] LOG - ${message}`;
}

//arrays
export function averageScore(ratings: number[]) {

  let sum:number = 0;
  for (const i in ratings) {
    sum += ratings[i];
  }
  
  return sum / ratings.length;
}

const nums: number[] = [12,3232,125,83,19];

console.log(averageScore(nums));

//types with array
export type ArArNum = Array<Array<number>>;
