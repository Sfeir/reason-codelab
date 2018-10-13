open Belt;

let sum = (a, b) => a + b;

{
  let command = Node.Process.argv->Array.sliceToEnd(2);
  let result = command->Array.map(int_of_string)->Array.reduce(0, sum);
  Js.log(result);
};