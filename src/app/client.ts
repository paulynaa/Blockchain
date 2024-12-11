import { createThirdwebClient } from "thirdweb";
import { ThirdwebSDK } from "@thirdweb-dev/sdk";
import { localhost } from "thirdweb/chains";

const clientId = process.env.NEXT_PUBLIC_TEMPLATE_CLIENT_ID;

if (!clientId) {
  throw new Error("No client ID provided");
}

// Initialize the SDK with a custom localhost chain configuration
const sdk = new ThirdwebSDK({
  chain: {
    ...localhost,
    rpc: ["http://127.0.0.1:7545"], // Set the Ganache RPC URL
  },
});

// Create the client with the SDK
export const client = createThirdwebClient({
  clientId: clientId,
  sdk,
});
