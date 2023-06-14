def rule1(symptoms):
    if 'fever' in symptoms and 'headache' in symptoms:
        return 'You may have flu'
    return None


def rule2(symptoms):
    if 'pain' in symptoms and 'bruising' in symptoms and 'swelling' in symptoms:
        return 'You may have a fracture'
    return None


def rule3(symptoms):
    if 'stomachache' in symptoms and 'yellow nails' in symptoms and 'yellow eyes' in symptoms:
        return 'You may have jaundice'
    return None


def rule4(symptoms):
    if 'chest pain' in symptoms and 'breathelessness' in symptoms:
        return 'You may be having a heart attack! Get medical service asap!'
    return None


def rule5(symptoms):
    if 'runny nose' in symptoms and 'sneezing' in symptoms:
        return 'You may have cold'
    return None


def rule6(symptoms):
    if 'cough' in symptoms and 'breathelessness' in symptoms:
        return 'You may have cough'
    return None


def diagnosis(symptoms):
    rules = [rule1, rule2, rule3, rule4, rule5, rule6]
    results = []
    for rule in rules:
        result = rule(symptoms)
        if result:
            results.append(result)
    if len(results) == 0:
        return 'Sorry we could not diagnose your symptoms'
    elif len(results) == 1:
        return results[0]
    else:
        return 'You may have multiple conditions: '+', '.join(results)


def ask():
    print("Enter your symptoms one by one: (type exit when done)")
    symptoms = []
    while (True):
        x = input("Enter symptom: ")
        if x == "exit" or x == "Exit" or x == "EXIT":
            break
        symptoms.append(x)

    print(diagnosis(symptoms))


ask()
