# ReasonML CodeLab - DevFest Nantes

1. After cloning...

- run `npm install`
  this will install the bucklescript toolchain
  inculding the OCaml compiler - so be patient!

- run `npm start`
  this will compile everything under `src`
  and generate .bs.js files alongside your .re files

- run `node src/one/Calculator.bs.js` (and others)
  bucklescript generates commonJS modules ready for nodeJS

2. Setup an empty project

- install bs-platform globally `npm i -g bs-platform`
- run `bsb -init . -theme basic-reason`
- explore project structure and dependencies
- start compiler in watch mode with `npm start`
- run compiled JS: `node src/Demo.bs.js`

  - js in repository yes or no ? (no)
