const readline = require("readline");
const { make } = require("./RevCalc.bs");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const calc = make();

const ask = prompt =>
  rl.question(prompt && prompt + " ", input => ask(calc(input).join(" ")));
ask("");
