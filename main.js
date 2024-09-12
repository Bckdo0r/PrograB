const N = +prompt("N alumnos")

const students = []

for (let i = 0; i < N; i++) {
	const name = prompt("Nombre", i)
	const grades = []
	for (let j = 1; j <= 3; j++) {
		grades[i] = +prompt("Nota", j)
	}

	const avg = grades.reduce((acc, cur) => acc+cur, 0) / grades.length
	
	students.push({
		name,
		grades,
		avg
	})	
}

const [{ name }] = students.sort((a, b) => b.avg - a.avg)

console.log(name)