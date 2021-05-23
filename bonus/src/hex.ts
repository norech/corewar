
export function getHex(d: string)
{
	return new TextEncoder().encode(d).reduce((prev, curr, index, arr) => {
		const left = (index % 16 === 0 ? index.toString(16).padStart(6, 0) + '  ' : ' ')
		const bytes = curr.toString(16).padStart(2, 0);
		let text = "";
		if (index === arr.length - 1 || index % 16 === 15)
			text = ' '.repeat((15 - index % 16) * 3)
			+ Array.from(arr).splice(index - index % 16, 16)
					.reduce((last, val) => {
						let reduced = last;
						if (val > 31 && val < 127 || val > 159)
							reduced += String.fromCharCode(val);
						else
							reduced += '.';
						return reduced;
					}, '  ')
			+ '\n';

		return prev + left + bytes + text
	}, '');
}