open Belt;

type entry =
  | Add
  | Mult
  | Num(float)
  | Unknown;

let parse = token =>
  try (float_of_string(token)->Num) {
  | Failure(_) =>
    switch (token) {
    | "+" => Add
    | "*" => Mult
    | _ => Unknown
    }
  };

let calc = (stack, input) =>
  switch (parse(input), stack) {
  | (Num(n), stack) => [n, ...stack]
  | (Add, [a, b, ...t]) => [a +. b, ...t]
  | (Mult, [a, b, ...t]) => [a *. b, ...t]
  | _ => stack
  };

let make = () => {
  let stack = ref([]);

  input => {
    let newStack = calc(stack^, input);
    stack := newStack;
    List.(newStack->reverse->map(string_of_float)) |> String.concat(" ");
  };
};