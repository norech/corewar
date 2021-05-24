<script lang="ts">
	import createCompiler from "./compiler";
	import { getHex } from "./hex";

	export let input: string = `.name "Abel"
.comment "L'amer noir."

	sti r1, %:hi, %1

hi:	live %234
	ld %0, r3
	zjmp %:hi`;

	let outputBytes = "";
	export let has_error = false;
	export let output: string = "";
	export let preview: string;
	export let errors: string[] = [];

	function saveOutputFile() {
		var blob = new Blob([outputBytes], {
			type: 'application/octet-stream'
		});
		var link = document.createElement("a");
		link.href = window.URL.createObjectURL(blob);
		link.download = "champion.cor";
		link.click();
	}

	async function onChange() {
		const compiler = await createCompiler();

		try {
			output = "";
			outputBytes = compiler.compileString(input);
			output = getHex(outputBytes);
			errors = [];
			has_error = false;
		} catch (err) {
			errors = err.errors;
			has_error = true;
		}
	}
	onChange();
</script>

<main>

	<div>
		<textarea on:input="{() => onChange()}" bind:value={input}></textarea>
		<textarea value={output} disabled></textarea>
	</div>
	<button disabled={has_error} on:click="{() => saveOutputFile()}">Save .cor</button>
	<div class="errors">
		<ul>
			{#if errors.length > 0}
				Errors:
				<pre><code>
					{#each errors as error}
						{ error + "\n" }
					{/each}
				</code></pre>
			{/if}
		</ul>
	</div>
</main>

<style>
	main {
		text-align: center;
		padding: 1em;
		max-width: 240px;
		margin: 0 auto;
	}

	h1 {
		color: #ff3e00;
		text-transform: uppercase;
		font-size: 4em;
		font-weight: 100;
	}

	@media (min-width: 640px) {
		main {
			max-width: none;
		}
	}

	textarea { width: 40%; height: 500px; }
</style>