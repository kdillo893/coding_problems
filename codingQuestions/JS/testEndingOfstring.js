function confirmEnding(str, target) {

  //two ways:

  ///slice from the end of str for the length of target... test if it matches the expected target
  // let substr = str.slice(str.length - target.length);
  // return str.slice(str.length - target.length) === target;

  ///regex test against end of string with /${target}$/ ... this would take some knowledge of syntax.
  const regexTarget = new RegExp(target+"$");
  return regexTarget.test(str);
}

confirmEnding("Bastian", "n");
