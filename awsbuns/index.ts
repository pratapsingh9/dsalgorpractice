import { z } from "zod";

export const userSchema = z.object({
  name: z.string().min(8, {
    message: "Must be 8 char long",
  }),
  id: z.number().nonnegative(),
});

export const userProductSchema = z.object({
  email: z.string().email().min(8, {}),
});
