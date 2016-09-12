.name "bidon"
.comment "je suis bidon"

sti	r1, %:live, %1
fork	%:fist

fist:
	live	%10
	sti	r1, %:live, %1
	fork	%:fist

live:
live %1
fork	%:fist

