lista = ["acucar", "arroz", "azeite", "biscoito", "cafe", "carne", "frango", "farinha", "feijao", "fermento", "iogurte", "leite", "macarrao", "manteiga", "molho", "oleo", "ovos", "paes", "polpas", "queijo", "requeijao", "sal", "temperos", "abacate", "abacaxi", "alface", "alho", "banana", "batata", "brocolis", "cebola", "cenoura", "coco", "couve", "espinafre", "figo", "goiaba", "laranja", "limao", "maca", "mamao", "manga", "maracuja", "melancia", "melao", "pera", "pessego", "pimentao", "tangerina", "tomate", "uva", "guardanapo", "papel_aluminio", "papel_filme", "papel_toalha", "absorventes", "algodao", "barbeador", "cotonetes", "creme_dental", "desodorante", "escova_dente", "fio_dental", "papel_higienico",
"shampoo_condicionador", "agua_sanitaria", "alcool", "amaciante", "desinfetante", "detergente", "esponja_aco", "esponja_pia", "flanelas", "luvas_plasticas", "sabao_pedra", "sabao_po"]

lista_alias = ["Açúcar", "Arroz", "Azeite", "Biscoito", "Café", "Carne", "Frango", "Farinha", "Feijão", "Fermento", "Iogurte", "Leite", "Macarrão", "Manteiga", "Molho", "Óleo", "Ovos", "Pães", "Polpas", "Queijo", "Requeijão", "Sal", "Temperos", "Abacate", "Abacaxi", "Alface", "Alho", "Banana", "Batata", "Brócolis", "Cebola", "Cenoura", "Coco", "Couve", "Espinafre", "Figo", "Goiaba", "Laranja", "Limão", "Maça", "Mamão", "Manga", "Maracujá", "Melancia", "Melão", "Pera", "Pêssego", "Pimentão", "Tangerina", "Tomate", "Uva", "Guardanapo de papel", "Papel alumínio", "Papel filme", "Papel toalha", "Absorventes", "Algodão", "Barbeador descartável", "Cotonetes", "Creme dental", "Desodorante", "Escova de dente", "Fio dental", "Papel higiênico", "Shampoo e condicionador", "Água sanitária", "Álcool em gel", "Amaciante", "Desinfetante", "Detergente", "Esponja de aço", "Esponja de pia", "Flanelas", "Luvas plásticas", "Sabão em pedra", "Sabão em pó",
]

#lista.each { |l| puts l.capitalize }

puts "#Input boolean"
lista.zip(lista_alias).each do |l, a|
	puts l + ":\n  name: " + a
end

puts "\n#Groups"
lista.each do |l|
	puts "    - input_boolean." + l
end
