import re
import random

rules = {
    'greetings': {
        'patterns': [r'Hello', r'Hi', r'Hey'],
        'responses': ["Hello! Welcome to out Food ordering service!", "Hello! How can I help you?"]
    },
    'menu': {
        'patterns': [r'menu', r'options'],
        'responses': ['1. Pizza\n2. Sandwiches\n3. Burger\n4. Drinks\n5. Vada Pav\n']
    },
    'food': {
        'patterns': [r'Pizza', r'Sandwich', r'Burger', r'Drink', r'Vada Pav'],
        'responses': ["Okay! Do you want to confirm your order?"]
    },
    'confirm': {
        'patterns': [r'confirm', r'yes I want to confirm'],
        'responses': ["Okay! You will receive your order within 30 minutes"]
    },
    'change': {
        'patterns': [r'change'],
        'responses': ["What change would you like to make?"]
    },
    'order': {
        'patterns': [r'order', r'I want to order'],
        'responses': ["What would you like to order?"]
    },
    'order change': {
        'patterns': [r'instead'],
        'responses': ["Okay!  You will receive your order within 30 minutes"]
    },
    'gratitude': {
        'patterns': [r'thank'],
        'responses': ["You're Welcome!"]
    },
    'cancel': {
        'patterns': [r'cancel'],
        'responses': ["Cancelling your order! Sorry for the inconvenience!"]
    },
    'goodbye': {
        'patterns': [r'bye', r'goodbye'],
        'responses': ["Thank you for utilizing our service!"]
    },
    'okay': {
        'patterns': [r'ok', r'okay'],
        'responses': ["Fine!"]
    },
    'default': {
        'responses': ["Sorry! I didn't understand! Can you please rephrase your concern?"]
    }
}


def match_patterns(user_input, patterns):
    for pattern in patterns:
        match = re.search(pattern, user_input, re.IGNORECASE)
        if match:
            return True
    return False


def get_responses(user_input):
    for intent, data in rules.items():
        patterns = data.get('patterns')
        if patterns and match_patterns(user_input, patterns):
            responses = data.get('responses')
            return random.choice(responses)
    return random.choice(rules['default']['responses'])


def chat():
    print("Hello! Welcome to our food ordering service!")

    while True:
        user = input("User: ")
        chat_response = get_responses(user)
        print("ChatBot:", chat_response)

        if any(re.search(pattern, user) for pattern in rules['goodbye']['patterns']):
            break


chat()
