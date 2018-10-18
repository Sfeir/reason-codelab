open Express;

let logUnknownGet = (req, res, _) => {
  Js.log2("unknown GET:", Request.path(req));
  Response.sendStatus(res, 404);
};

let logUnknownPost = (req, res, _) => {
  Js.log2("unknown POST:", Request.path(req));
  Js.log(Request.json(req));
  Response.sendStatus(res, 404);
};

let startServer = port => {
  let app = makeApp();

  App.(
    app
    ->use(json())
    ->get("/", Core.sayHelloWorld)
    ->get("/vol/:rad", Core.volume)
    ->get("*", logUnknownGet)
    ->post("/fact", Core.factorial)
    ->post("*", logUnknownPost)
    ->listen(port, () => Js.log("listening on port " ++ string_of_int(port)))
  );
};