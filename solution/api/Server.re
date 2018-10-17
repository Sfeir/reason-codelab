open Express;

let sayHelloWorld = (_, res, _) => Response.send(res, "Hello World!");

let startServer = port => {
  let app = makeApp();

  App.(
    app
    ->get("/", sayHelloWorld)
    ->listen(port, () => Js.log("listening on port " ++ string_of_int(port)))
  );
};