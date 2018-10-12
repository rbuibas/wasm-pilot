Hello WebAseembly !

Sample for compiling a C file:
emcc -o hello3.html hello3.c -O3 -s WASM=1 --shell-file html_template/shell_minimal.html -s NO_EXIT_RUNTIME=1  -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']

Mind the quotation marks.
The original command had: ...EXTRA_EXPORTED_RUNTIME_METHODS='["ccall"]'

Also, what MDN doesn't mention is that you need to serve the HTML page.
Command: emrun --no_browser --port 8080 .
From the folder where you have the code, hence the DOT.


Using also:

<button class="mybutton">Prime IT</button>

document.querySelector('.mybutton').addEventListener('click', function(){
  var result = Module.ccall('wasmMain', // name of C function 
                             null, // return type
                             null, // argument types
                             null); // arguments
});