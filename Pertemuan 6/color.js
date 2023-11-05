// objek Tetrahedron : rgba(200, 55, 180, 1)
// objek Tetrahedron : rgba(0.784, 0.215, 0.392, 1)

// objek Octahedron : rgba(200, 147, 55, 1)
// objek Octahedron : rgba(0.784, 0.576, 0.215, 1)

// objek Dodecahedron : rgba(231, 37, 24, 1)
// objek Dodecahedron : rgba(0.905, 0.145, 0.094, 1)

// objek Icosahedron : rgba(98, 183, 252, 1)
// objek Icosahedron : rgba(0.384, 0.717, 0.988, 1)

// objek Pentagon Prism : rgba(55, 108, 200, 1)
// objek Pentagon Prism : rgba(0.215, 0.423, 0.784, 1)

// objek Pentagon Antiprism : rgba(55, 200, 75, 1)
// objek Pentagon Antiprism : rgba(0.215, 0.784, 0.294, 1)

let arr = [
    [200, 55, 100, 255],
    [200, 147, 55, 255],
    [231, 37, 24, 255],
    [98, 183, 252, 255],
    [55, 108, 200, 255],
    [55, 200, 75, 255]
];

for (let i = 0; i < arr.length; i++) {
    arr[i].forEach(item => {
        console.log([item/255]);
    })
}
    
