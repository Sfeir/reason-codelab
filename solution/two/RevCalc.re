open Belt;

type entry =
  | Add
  | Mult
  | Num(float)
  | Unknown(string);

let parse = token =>
  try (float_of_string(token)->Num) {
  | Failure(_) =>
    switch (token) {
    | "+" => Add
    | "*" => Mult
    | s => Unknown(s)
    }
  };

let calc = (stack, input) =>
  Result.(
    switch (parse(input), stack) {
    | (Num(n), stack) => Ok([n, ...stack])
    | (Add, [a, b, ...t]) => Ok([a +. b, ...t])
    | (Mult, [a, b, ...t]) => Ok([a *. b, ...t])
    | (Unknown(s), _) => Error("I don't understand " ++ s)
    | _ => Error("Not enough params")
    }
  );

let formatStack = stack =>
  List.(stack->reverse->map(string_of_float)) |> String.concat(" ");

let make = () => {
  let stack = ref([]);

  input =>
    switch (calc(stack^, input)) {
    | Ok(newStack) =>
      stack := newStack;
      formatStack(newStack);
    | Error(err) => err ++ "\n" ++ formatStack(stack^)
    };
};