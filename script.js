// ==============================
// MunchMate Food Prices
// ==============================

let prices = {
    // Meals
    "Fish Fillet": 128,
    "Sisig": 135,
    "Beef Steak": 120,
    "Adobo": 85,
    "Liempo": 135,

    // Snacks
    "Churros": 100,
    "French Fries": 45,
    "Spaghetti": 75,
    "Beef Burger": 32,
    "Mango Float": 120,

    // Beverages
    "Mango Shake": 75,
    "Buko Pandan": 50,
    "Iced Tea": 33,
    "Coke": 20,
    "Sprite": 20
};


// ==============================
// Order Array
// ==============================

let order = [];

let selectedFood = "";
let selectedPrice = 0;
let customerName = "";
let referenceNumber = "";

// ==============================
// Start Ordering
// ==============================

function startOrdering() {

    document.getElementById("welcomeScreen").style.display = "none";

    document.getElementById("nameScreen").style.display = "block";
}


// ==============================
// Continue to Menu
// ==============================

function continueToMenu() {
    customerName =
        document.getElementById("customerName").value.trim();

    if (customerName === "") {
        showMessage("Please enter your name.");
        return;
    }

    document.getElementById("nameScreen").style.display = "none";
    document.getElementById("menuScreen").style.display = "block";
}


// ==============================
// Choose Category
// ==============================

function chooseCategory(category) {

    if (category === "Meals") {

        document.getElementById("menuScreen").style.display = "none";

        document.getElementById("mealsScreen").style.display = "block";
    }


    if (category === "Snacks") {

        document.getElementById("menuScreen").style.display = "none";

        document.getElementById("snacksScreen").style.display = "block";
    }


    if (category === "Beverages") {

        document.getElementById("menuScreen").style.display = "none";

        document.getElementById("beveragesScreen").style.display = "block";
    }
}


// ==============================
// Choose Food
// ==============================

function chooseFood(food) {

    selectedFood = food;
    selectedPrice = prices[food];

    document.getElementById("mealsScreen").style.display = "none";
    document.getElementById("snacksScreen").style.display = "none";
    document.getElementById("beveragesScreen").style.display = "none";

    document.getElementById("quantityScreen").style.display = "block";

    document.getElementById("selectedFood").textContent =
        "How many " + food + " would you like?";
}

// ==============================
// Confirm Quantity
// ==============================

function confirmQuantity() {

    let quantity = Number(
        document.getElementById("quantityInput").value
    );

    if (quantity <= 0) {
       showMessage("Please enter a valid quantity.");
        return;
    }

    let existingIndex = order.findIndex(
        item => item.food === selectedFood
    );

    if (existingIndex !== -1) {

        order[existingIndex].quantity += quantity;

        order[existingIndex].subtotal =
            order[existingIndex].price *
            order[existingIndex].quantity;

    } else {

        let subtotal = selectedPrice * quantity;

        order.push({
            food: selectedFood,
            price: selectedPrice,
            quantity: quantity,
            subtotal: subtotal
        });
    }

    document.getElementById("quantityInput").value = "";

    showCart();
}

// ==============================
// Show Menu Again
// ==============================

function showMenu() {
    document.getElementById("cartScreen").style.display = "none";
    document.getElementById("mealsScreen").style.display = "none";
    document.getElementById("snacksScreen").style.display = "none";
    document.getElementById("beveragesScreen").style.display = "none";
    document.getElementById("quantityScreen").style.display = "none";
    document.getElementById("quantityInput").value = "";

    document.getElementById("menuScreen").style.display = "block";
}

// ==============================
// Show Payment
// ==============================

function showPayment() {
    if (order.length === 0) {
        showMessage("Your order is empty. Please add an item first.");
        return;
    }

    document.getElementById("cartScreen").style.display = "none";
    document.getElementById("paymentScreen").style.display = "block";

    document.getElementById("paymentInput").value = "";

    let total = 0;

    for (let item of order) {
        total += item.subtotal;
    }

    document.getElementById("paymentTotal").textContent =
        "Total to pay: ₱" + total;
}

// ==============================
// Confirm Payment
// ==============================

function confirmPayment() {

    let payment = Number(
        document.getElementById("paymentInput").value
    );

    if (payment <= 0) {
    showMessage("Please enter a valid payment amount.");
    return;
}
    let total = 0;

    for (let item of order) {
        total += item.subtotal;
    }

    if (payment < total) {
    showMessage("Insufficient payment. Please enter a higher amount.");
    return;
}

    let change = payment - total;

    referenceNumber =
    "MM-" + Math.floor(100000 + Math.random() * 900000);


    // Hide Payment Screen
    document.getElementById("paymentScreen").style.display = "none";

    // Show Receipt Screen
    document.getElementById("receiptScreen").style.display = "block";


    // Customer Name
    document.getElementById("receiptCustomer").textContent =
        "Customer: " + customerName;


    // Receipt Items
    let receiptItems = document.getElementById("receiptItems");

    receiptItems.innerHTML = "";

    for (let item of order) {

        receiptItems.innerHTML +=
            "<p>" +
            item.food +
            " - ₱" + item.price +
            " × " + item.quantity +
            " = ₱" + item.subtotal +
            "</p>";
    }


    // Receipt Total
    document.getElementById("receiptTotal").textContent = total;


    // Payment
    document.getElementById("receiptPayment").textContent =
        "Payment: ₱" + payment;


    // Change
    document.getElementById("receiptChange").textContent =
        "Change: ₱" + change;

    // Reference Number
    document.getElementById("receiptReference").textContent =
    "Reference #: " + referenceNumber;
}

// ==============================
// Show Cart
// ==============================

function showCart() {

    document.getElementById("mealsScreen").style.display = "none";
    document.getElementById("snacksScreen").style.display = "none";
    document.getElementById("beveragesScreen").style.display = "none";
    document.getElementById("quantityScreen").style.display = "none";

    document.getElementById("cartScreen").style.display = "block";
    document.getElementById("cartCustomer").textContent = "Customer: " + customerName;

    displayCart();
}

// ==============================
// Display Cart Items
// ==============================


function displayCart() {

    let cartItems = document.getElementById("cartItems");

    cartItems.innerHTML = "";

    let total = 0;

    for (let i = 0; i < order.length; i++) {

        let item = order[i];

        cartItems.innerHTML +=
            "<div class='cartItem'>" +
            "<strong>" + (i + 1) + ". " + item.food + "</strong>" +
            "<br>" +

            "₱" + item.price + " each" +
"<br><br>" +
'<button onclick="decreaseQuantity(' + i + ')">➖</button>' +
" " + item.quantity + " " +
'<button onclick="increaseQuantity(' + i + ')">➕</button>' +
"<br><br>" +
"<strong>Subtotal: ₱" + item.subtotal + "</strong>" +
            
            "<br>" +
            '<button onclick="removeItem(' + i + ')">❌ Remove</button>' +
            "</div>";

        total += item.subtotal;
    }

    document.getElementById("cartTotal").textContent = total;
}


// ==============================
// Start New Order
// ==============================

function startNewOrder() {
    order = [];
    selectedFood = "";
    selectedPrice = 0;
    customerName = "";
    referenceNumber = "";

    document.getElementById("customerName").value = "";

    document.getElementById("receiptScreen").style.display = "none";
    document.getElementById("welcomeScreen").style.display = "block";
}

// ==============================
// MunchMate Message
// ==============================

function showMessage(message) {
    document.getElementById("messageText").textContent = message;
    document.getElementById("messageBox").style.display = "block";
}

function closeMessage() {
    document.getElementById("messageBox").style.display = "none";
}

// ==============================
// Custom Remove Confirmation
// ==============================

let itemToRemove = -1;

function removeItem(index) {

    itemToRemove = index;

    let itemName = order[index].food;

    document.getElementById("confirmText").textContent =
        "Are you sure you want to remove " + itemName + "?";

    document.getElementById("confirmBox").style.display = "block";
}

function closeConfirm() {

    itemToRemove = -1;

    document.getElementById("confirmBox").style.display = "none";
}

function confirmRemove() {

    if (itemToRemove !== -1) {

        order.splice(itemToRemove, 1);

        itemToRemove = -1;

        displayCart();
    }

    document.getElementById("confirmBox").style.display = "none";
}

// ==============================
// Back to Cart
// ==============================

function backToCart() {
    document.getElementById("menuScreen").style.display = "none";
    document.getElementById("cartScreen").style.display = "block";

    displayCart();
}

// ==============================
// Increase Quantity
// ==============================

function increaseQuantity(index) {

    order[index].quantity++;

    order[index].subtotal =
        order[index].price * order[index].quantity;

    displayCart();
}

// ==============================
// Decrease Quantity
// ==============================

function decreaseQuantity(index) {

    if (order[index].quantity > 1) {

        order[index].quantity--;

        order[index].subtotal =
            order[index].price * order[index].quantity;

        displayCart();
    }
}